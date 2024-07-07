# # NOTE

1) In next greater or previous greater , whether start from start of array or end of array, the stack will  include decreasing elements from bottom of stack to the top of the stack.

```
    while (arr[st.top()]< arr[i]) {
        ...
        st.pop()
    }
    ....
```

2) In next smaller or previous smaller , whether start from start of array or end of array, the stack will  include increasing elements from bottom of stack to the top of the stack.

```
    while (arr[st.top()] > arr[i]) {
        ...
        st.pop()
    }
    ....
```