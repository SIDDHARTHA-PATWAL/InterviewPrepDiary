## NOTE

1) In "Best Time to Buy and Sell Stock with Transaction Fee" Problem, there can be confusion that if fee is larger than a selling price at a day, then it can be said , the person will only buy and will not sell due to transaction fee

```   
for eg . prices=[10,30] fee = 50
the person might think if he buys 10 and sell at 30 with 50 as fee , his profit will be -10+30-50 = -30
he might think instead he can have the transaction incomplete i.e buy at 10 and don't sell at 30, so profit will be  -10

But it should be noted that he can have larger profit(or less negative profit) by "not buying"
at the day 1 at 10 ,itself. so, profit will be "0"
```

This thing will be nicely handled by the taking the maximum of the two choices at day ( whether to "buy" or "not buy" ) 