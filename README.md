# paralell_programming
<head>
    <h1>C VS Go in parallel programming </h1>
</head>
<body>
    <h4> code was created in VS code </h4>
    <br/>
    tested on Intel Xeon W3580 @ 3.33GHz (Windows) &&  Intel I7 7500U @ 2.70GHz (Linux)
<br/>

C Program compilled by using gcc compiller ( for windows with MinGW gcc)
<br/>
Go Program compilled by using golang compiller

<h3>```sequential```</h3>

result of 100 test for `windows`
    go lang avg 10.60(s) \n
    c lang min avg 19.21(s)
    
result of 100 test for `linux`
    go lang min avg 27.38(s)
    c lang  min avg 16.006(s)

<h3>```parallel```</h3>

result of 100 test for `windows`
    go lang min avg 2.15(s)
    c lang min avg 4.33
    
result of 100 test for `linux`
    go lang min avg 10.33(s)
    c lang min avg 6.65(s)
</body>
