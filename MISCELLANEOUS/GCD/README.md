# GCD 

## Classical GCD ( Division Method )

###  TC->O(log(min(a,b))) SC->O(log(min(a,b)))
```
    int gcd(int a ,int b){
        return b==0? a: gcd(b, a%b);
    }
```

## STL GCD
```
    __gcd(a, b)
```