/*1.�������ݿ�*/
IF (EXISTS(SELECT * FROM master.dbo.sysdatabases WHERE dbid=db_ID('second_hand_book')))
BEGIN
USE master
ALTER DATABASE second_hand_book
SET single_user
WITH ROLLBACK IMMEDIATE
DROP DATABASE second_hand_book
END
create database second_hand_book
USE second_hand_book

/*2.�������ݿ��е����б�*/

/*רҵ��Major*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='Major')
	BEGIN
	use second_hand_book
	CREATE TABLE Major(
		majorNo CHAR(8) PRIMARY KEY CONSTRAINT majorNo_check CHECK(majorNo LIKE 'M[0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
		majorName varchar(20) NOT NULL
	)
	END
go

insert into  Major values ('M1600011','��Ϣ����');
insert into  Major values ('M1600012','��������');
insert into  Major values ('M1600013','���й���');
insert into  Major values ('M1600014','��ѧ');

insert into  Major values ('M1600021','�������ѧ�뼼��');
insert into  Major values ('M1600022','��������');
insert into  Major values ('M1600023','�Ƽ���');
insert into  Major values ('M1600024','����ý�弼��');

insert into  Major values ('M1600031','����Ӳ��');
insert into  Major values ('M1600032','��������');

insert into  Major values ('M1600041','�������');
insert into  Major values ('M1600042','���Ӳ��');

insert into  Major values ('M1600051','���ӿ�ѧ�뼼��');
insert into  Major values ('M1600052','΢����ѧ');
insert into  Major values ('M1600053','�������ѧ');

insert into  Major values ('M1600061','Ӣ�ţ�������');
insert into  Major values ('M1600062','Ӣ�ţ�����');
insert into  Major values ('M1600063','Ӣ�ţ��Ź�');

insert into  Major values ('M1600071','��������');
insert into  Major values ('M1600072','����');
insert into  Major values ('M1600073','Ӣ��');

insert into  Major values ('M1600081','�ǿ�');
insert into  Major values ('M1600082','��ҽ');
insert into  Major values ('M1600083','�Կ�');

/*ѧԺ��College*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='College')
	BEGIN
	use second_hand_book
	CREATE TABLE College(
		collegeNo CHAR(8) PRIMARY KEY CONSTRAINT collegeNo_check CHECK(collegeNo LIKE 'C[0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
		collegeName varchar(20) NOT NULL
	)
	END
go

insert into  College values ('C2021001','��������ѧԺ');
insert into  College values ('C2021002','�����ѧԺ');
insert into  College values ('C2021003','��еѧԺ');
insert into  College values ('C2021004','���ѧԺ');
insert into  College values ('C2021005','����ѧԺ');
insert into  College values ('C2021006','Ӣ��ѧԺ');
insert into  College values ('C2021007','�����ѧԺ');
insert into  College values ('C2021008','ҽѧԺ');

/*�û���myUser*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='myUser')
	BEGIN
	use second_hand_book
	CREATE TABLE myUser(
		myUserNo CHAR(8) PRIMARY KEY CONSTRAINT myUserNo_check CHECK(myUserNo LIKE 'E[0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
		collegeNo CHAR(8) NOT NULL FOREIGN KEY references College(collegeNo),
		majorNo CHAR(8) NOT NULL FOREIGN KEY references Major(majorNo),
		myUserName varchar(10) NOT NULL,
		telephone varchar(11) NOT NULL,
		address varchar(50) NOT NULL,
		entertime datetime NOT NULL
	)
	END
go

insert into  myUser values ('E0000001','C2021001','M1600011','������','189328934','���ӿƼ���ѧ��ˮ��С��������','20200815');
insert into  myUser values ('E0000002','C2021002','M1600021','��ΰ��','169328934','���ӿƼ���ѧ��ˮ��С��������','20210415');
insert into  myUser values ('E0000003','C2021003','M1600031','������','186778923','���ӿƼ���ѧ��ˮ��С��������','20200415');

/*�˻���Account*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='Account')
	BEGIN
	use second_hand_book
	CREATE TABLE Account(
		accountNo CHAR(8) PRIMARY KEY CONSTRAINT accountNo_check CHECK(accountNo LIKE 'A[0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
		myUserNo CHAR(8) NOT NULL FOREIGN KEY references myUser(myUserNo),
		balance Float(2) NOT NULL,
		tansaction INT NOT NULL 
	)
	END
go

insert into Account values ('A0000001','E0000001','64.50','16');
insert into Account values ('A0000002','E0000001','97.34','23');
insert into Account values ('A0000003','E0000001','0.00','0');
insert into Account values ('A0000004','E0000002','1006.00','8');
insert into Account values ('A0000005','E0000002','541.85','32');
insert into Account values ('A0000006','E0000002','21.50','2');
insert into Account values ('A0000007','E0000003','962.50','18');
insert into Account values ('A0000008','E0000003','28.50','4');
insert into Account values ('A0000009','E0000003','629.50','124');

/*��������OrderMaster*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='OrderMaster')
	BEGIN
	use second_hand_book
	CREATE TABLE OrderMaster(
		orderNo CHAR(8) PRIMARY KEY CONSTRAINT orderNo_check CHECK(orderNo LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
		buyer_accountNo CHAR(8) FOREIGN KEY references Account(accountNo),
		seller_accountNo CHAR(8) FOREIGN KEY references Account(accountNo),
		orderDate datetime NOT NULL,
		orderSum numeric(9,2),
		invoiceNo CHAR(10) UNIQUE
	)
	END
go

insert into OrderMaster values ('22060001','A0000001','A0000004','20220601','300.60','I000000001');
insert into OrderMaster values ('22060002','A0000002','A0000004','20220601','42.60','I000000002');
insert into OrderMaster values ('22060003','A0000003','A0000009','20220602','86.20','I000000003');
insert into OrderMaster values ('22060004','A0000004','A0000008','20220602','45.20','I000000004');
insert into OrderMaster values ('22060005','A0000007','A0000002','20220604','47.90','I000000005');
insert into OrderMaster values ('22060006','A0000008','A0000005','20220605','63.10','I000000006');
insert into OrderMaster values ('22060007','A0000002','A0000006','20220606','100.80','I000000007');
insert into OrderMaster values ('22060008','A0000009','A0000001','20220606','67.90','I000000008');
insert into OrderMaster values ('22060009','A0000006','A0000003','20220607','65.20','I000000009');
insert into OrderMaster values ('22060010','A0000005','A0000007','20220608','110.30','I000000010');

/*ͼ������bookClass*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='bookClass')
	BEGIN
	use second_hand_book
	CREATE TABLE bookClass(
		bookclassNo CHAR(8) PRIMARY KEY CONSTRAINT bookclassNo_check CHECK(bookclassNo LIKE 'BC[0-9][0-9][0-9][0-9][0-9][0-9]'),
		bookclassName varchar(20) NOT NULL
	)
	END
go

insert into  bookClass values ('BC201601','������');
insert into  bookClass values ('BC201602','������');
insert into  bookClass values ('BC201603','������');
insert into  bookClass values ('BC201604','��Ϣ��');
insert into  bookClass values ('BC201605','��ѧ��');

/*ͼ���Book*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='Book')
	BEGIN
	use second_hand_book
	CREATE TABLE Book(
		bookNo CHAR(8) PRIMARY KEY CONSTRAINT bookNo_check CHECK(bookNo LIKE 'B[0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
		bookclassNo CHAR(8) FOREIGN KEY references bookClass(bookclassNo),
		bookName varchar(20) NOT NULL,
		bookprice numeric(7,2)
	)
	END
go

insert into  Book values ('B2016001','BC201601','python����Ӧ��',20.00);
insert into  Book values ('B2016002','BC201601','java������',65.10);
insert into  Book values ('B2016003','BC201601','go������',75.32);
insert into  Book values ('B2016004','BC201601','c������',21.30);
insert into  Book values ('B2016005','BC201602','����֮��',86.20);
insert into  Book values ('B2016006','BC201602','���ƹ���֮��',75.25);
insert into  Book values ('B2016007','BC201602','��ǿ���۹���',90.20);
insert into  Book values ('B2016008','BC201602','����̸����',100.20);
insert into  Book values ('B2016009','BC201603','����������',25.36);
insert into  Book values ('B2016010','BC201603','����Ħ',75.30);
insert into  Book values ('B2016011','BC201603','�����赼',45.20);
insert into  Book values ('B2016012','BC201603','������',56.20);
insert into  Book values ('B2016013','BC201604','��Ϣ��ը',24.38);
insert into  Book values ('B2016014','BC201604','��Ϣ����',47.90);
insert into  Book values ('B2016015','BC201604','��ϢVR',85.20);
insert into  Book values ('B2016016','BC201604','��ϢAR',63.10);
insert into  Book values ('B2016017','BC201605','����ͼ��ѧ',45.80);
insert into  Book values ('B2016018','BC201605','�ո�������ѧ��',65.80);
insert into  Book values ('B2016019','BC201605','Ī����ѧ',45.78);
insert into  Book values ('B2016020','BC201605','�����ѧ',100.80);

/*������ϸ��OrderDetail*/
if NOT EXISTS (SELECT * FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_NAME='OrderDetail')
	BEGIN
	use second_hand_book
	CREATE TABLE OrderDetail(
		orderNo CHAR(8) NOT NULL FOREIGN KEY references OrderMaster(orderNo),
		productNo CHAR(8) NOT NULL FOREIGN KEY references Book(bookNo),
		quantity int NOT NULL,
		price numeric(7,2),
		PRIMARY KEY(orderNo,productNo),
	)
	END
go

insert into OrderDetail values ('22060001','B2016008',3,100.20);
insert into OrderDetail values ('22060002','B2016004',2,21.30);
insert into OrderDetail values ('22060003','B2016005',1,86.20);
insert into OrderDetail values ('22060004','B2016011',1,45.20);
insert into OrderDetail values ('22060005','B2016014',1,47.90);
insert into OrderDetail values ('22060006','B2016016',1,63.10);
insert into OrderDetail values ('22060007','B2016020',1,100.80);
insert into OrderDetail values ('22060008','B2016014',1,47.90);
insert into OrderDetail values ('22060008','B2016001',1,20.00);
insert into OrderDetail values ('22060009','B2016011',1,45.20);
insert into OrderDetail values ('22060009','B2016001',1,20.00);
insert into OrderDetail values ('22060010','B2016011',1,45.20);
insert into OrderDetail values ('22060010','B2016002',1,65.10);

