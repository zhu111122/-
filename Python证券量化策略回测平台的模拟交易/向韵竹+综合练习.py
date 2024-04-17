# -*- coding: utf-8 -*-
"""
Created on Sat Dec 19 13:44:39 2020

@author: 21734
"""

import csv
import datetime

class account:#账户
    def __init__(self,money):
        self.__money = money#现金
        self.__stock = {}#持有股票（ts_code : number）
        self.__asset = money#总资产
        with open ('operation.xls','a+',encoding='utf-8') as f:#在生成账户的同时，同时生成表头
            f.write("交易日期\t交易类型\t标的\t价格\t数量\t佣金\t契税\t总费用\n")
            
        with open ('user.xls','a+',encoding='utf-8') as f:#在生成账户的同时，同时生成表头
            f.write('日期\t证券市值\t剩余现金\t总资产\n')
    
    def info(self):#用以获得所有的信息
        return self.__money,self.__stock,self.__asset
    
    def change_info(self,info):#用以修改所有的信息
        self.__money,self.__stock,self.__asset = info
        

class commander:#指令
    def __init__(self):
        with open("trade_commands.csv","r") as file:#打开文件
            reader = csv.DictReader(file)#读取数据
            reader = list(reader)#将指令转换为列表格式， 列表中的每一项都是一个由表头指定的字典
            self.__commands = reader#将读取到的内容赋给指令
    
    def today_commands(self,day):#返回每天需要购买和卖出的股票的ts_code
        BUY_stocks =[]#声明一个空列表，用以储存需要购买的股票
        SELL_stocks =[]#声明一个空列表，用以储存需要卖出的股票
        for each in self.__commands:#访问所有的指令
            if each["date"] == day:#如果日期与传入的日期相同
                if each['trade_type'] == 'BUY':#如果指令是购买
                    BUY_stocks.append(each['trade_stock'])#添加ts_code到BUY中
                elif each['trade_type'] == 'SELL':
                    SELL_stocks.append(each['trade_stock'])#添加ts_code到SELL中
        return BUY_stocks,SELL_stocks#返回需要购买和卖出的股票代码
    
    
class calendar:#日期
    def __init__(self):#生成时提取操作指令中所有的日期
         with open("trade_commands.csv","r") as file:#打开文件
            reader = csv.DictReader(file)#读取数据
            dates = [row['date'] for row in reader ]#生成一个含所有日期的列表
            temp = {}#定义一个临时的空字典
            date = temp.fromkeys(dates)#利用字典的属性提取不重复的所有日期
            self.__dates = list(date.keys())#将不重复的日期转换为列表并赋值给dates
    
    def generator(self):#遍历所有日期
        for day in self.__dates:#产生一个生成器，用以在操作时遍历所有的有操作的日期
            yield day


class operater:#操作员
    def __init__(self,info,today):
        self.__today = today
        self.__money,self.__stock,self.__asset = info
    
    def BUY(self,stocks):#购买操作
        if len(stocks) == 0:
            pass
        else:
            buys = {}
            prices = {}
            #对日期进行操作，先转换为日期类型再按格式转换为字符串格式，方便匹配ldays当中的文件名
            day = self.__today#
            day = day.split('-')
            day = datetime.date(int(day[0]), int(day[1]),int(day[2]))
            day = day.strftime('%Y-%m-%d')
            with open ('ldays/'+str(day)+'.csv','r') as info:#用相对路径访问文件
                reader = csv.DictReader(info)#读取数据
                infomation = list(reader)
            for each in infomation:
                try:
                    integer = each['close_adj'].split('.')[0]
                    decimals = each['close_adj'].split('.')[1]
                    each_number = int(integer) + int(decimals)*(0.1**len(decimals))
                except IndexError:
                    #print(each['close_adj'])
                    pass#是一堆空格
                prices[each['ts_code']] = each_number
            command = 'BUY'
            number = len(stocks)#要购买的股票的数量
            average_money = self.__money*(1-3/10000)/number#每支股票可用的金额
            for stock in stocks:#遍历所有要购买的股票
                if stock in self.__stock.keys():#检查是否已经在购买的股票中
                    pass
                else:
                    buys[stock] = int(average_money/float(prices[stock])//100 *100)#生成一个要购买股票的股数的字典
            for key in buys:#遍历要买的股票的字典
                cost = 0
                cost = float(prices[key]*buys[key])#总开销
                buy_fee = float(cost*3/10000)#计算佣金
                if buy_fee < 5:#如果佣金不足五元，佣金为5元
                    buy_fee = 5
                else:
                    pass
                tax = 0#购买时没有税，但为了保持输出的一致性，
                fees = tax + buy_fee#计算总费用
                #记录交易
                operation_information=str(self.__today)+'\t'+str(command)+'\t'+str(key)+'\t'+str(prices[key])+'\t'+str(buys[key])+'\t'+str(buy_fee)+'\t'+str(tax)+'\t'+str(fees)+'\n'
                with open ('operation.xls','a+',encoding='utf-8') as f:
                    f.write(operation_information)
                #用以修改现金和持股
                self.__money = self.__money - fees - cost
                self.__stock[key] = buys[key]
            total_value = 0#计算股票的总金额
            for stock in self.__stock:
                total_value = total_value + prices[stock]*int(self.__stock[stock])
                self.__asset = self.__money + total_value
            
            #因为除第一天只买之外，其余所有的天数都又买又卖，且先卖后买，所以用户信息仅需要在每次购买完当天的股票后写入
            user_info = str(self.__today)+'\t'+str(total_value)+'\t'+str(self.__money)+'\t'+str(self.__asset) + '\n'
            with open ('user.xls','a+',encoding='utf-8') as f:
                f.write(user_info)
        return self.__money,self.__stock,self.__asset
      
        
    def SELL(self,stocks):
        if len(stocks) == 0:
            pass
        else:
            prices = {}
            have = self.__stock#持有股票
            day = self.__today
            day = day.split('-')
            day = datetime.date(int(day[0]), int(day[1]),int(day[2]))
            day = day.strftime('%Y-%m-%d')
            with open ('ldays/'+str(day)+'.csv','r') as info:#用相对路径访问文件
                reader = csv.DictReader(info)#读取数据
                infomation = list(reader)
            for each in infomation:#处理股票价格，因为字符型转浮点型出错，所以拆分后转换为浮点数
                try:
                    integer = each['close_adj'].split('.')[0]
                    decimals = each['close_adj'].split('.')[1]
                    each_number = int(integer) + int(decimals)*(0.1**len(decimals))
                except IndexError:
                    #print(each['close_adj'])
                    pass#是一堆空格
                prices[each['ts_code']] = each_number
            command = 'SELL'#将操作类型赋给command，便于输出
            for stock in stocks:#遍历需要卖出的股票
                get = float(prices[stock]) * int(have[stock])
                sell_fee = get *3/10000
                if sell_fee < 5:#如果佣金不足五元，佣金为5元
                    sell_fee = 5
                else:
                    pass
                tax = get*0.1/100#税款为交易总额的千分之一
                fees = sell_fee + tax#总费用是税款加佣金
                #记录交易
                operation_information=str(self.__today)+'\t'+str(command)+'\t'+str(stock)+'\t'+str(prices[stock])+'\t'+str(have[stock])+'\t'+str(sell_fee)+'\t'+str(tax)+'\t'+str(fees)+'\n'
                with open ('operation.xls','a+',encoding='utf-8') as f:
                    f.write(operation_information)
                    
                #用以修改现金和持股
                self.__money = self.__money - fees + get
                self.__stock.pop(stock)
            total_value = 0#计算股票的总金额
            for stock in self.__stock:
                total_value = total_value + prices[stock]*int(self.__stock[stock])
                self.__asset = self.__money + total_value
        return self.__money,self.__stock,self.__asset  
                 

            
UserA = account(10000000)#初始化账户类，初始资金一千万
dates = calendar()#初始化一个日期类，读取日期
days = dates.generator()#产生一个日期的生成器
commands = commander()#读取所有的操作
for day in days:#遍历日期
    today_buy,today_sell = commands.today_commands(day)#得到今天要买卖的股票名称
    oper = operater(UserA.info(), day)#初始化一个操作员，操作当天的买卖
    info = oper.SELL(today_sell)#进行卖出操作
    UserA.change_info(info)#更改账户信息
    oper = operater(UserA.info(), day)#重新初始化操作员，更新账户信息
    info = oper.BUY(today_buy)#进行购买操作
    UserA.change_info(info)#更改账户信息

print("done")#全部运行完成后，输出“done”
    
    

