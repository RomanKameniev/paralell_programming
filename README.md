# paralell_programming
<head>
    <title>C VS Go in parallel programming </title>
    
    code was created in VS code 
    
    tested on Intel Xeon W3580 @ 3.33GHz (Windows) &&  Intel I7 7500U @ 2.70GHz (Linux)

</head>



C Program compilled by using gcc compiller ( for windows with MinGW gcc)
Go Program compilled by using golang compiller

```sequential```

result of 100 test for `windows`
    go lang avg 10.60(s) \n
    c lang min avg 19.21(s)
    
result of 100 test for `linux`
    go lang min avg 27.38(s)
    c lang  min avg 16.006(s)

```parallel```

result of 100 test for `windows`
    go lang min avg 2.15(s)
    c lang min avg 4.33
    
result of 100 test for `linux`
    go lang min avg 10.33(s)
    c lang min avg 6.65(s)
