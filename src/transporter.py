<body bgcolor="#f0f0f8"><font color="#f0f0f8" size="-5"> -->
<body bgcolor="#f0f0f8"><font color="#f0f0f8" size="-5"> --> -->
</font> </font> </font> </script> </object> </blockquote> </pre>
</table> </table> </table> </table> </table> </font> </font> </font><body bgcolor="#f0f0f8">
<table width="100%" cellspacing=0 cellpadding=2 border=0 summary="heading">
<tr bgcolor="#6622aa">
<td valign=bottom>&nbsp;<br>
<font color="#ffffff" face="helvetica, arial">&nbsp;<br><big><big><strong>&lt;type 'exceptions.UnboundLocalError'&gt;</strong></big></big></font></td
><td align=right valign=bottom
><font color="#ffffff" face="helvetica, arial">Python 2.7.12: /usr/bin/python<br>Thu Apr 13 22:55:15 2017</font></td></tr></table>
    
<p>A problem occurred in a Python script.  Here is the sequence of
function calls leading up to the error, in the order they occurred.</p>
<table width="100%" cellspacing=0 cellpadding=0 border=0>
<tr><td bgcolor="#d8bbff"><big>&nbsp;</big><a href="file:///home/2017/jnimij/public_html/cgi-bin/transporter.py">/home/2017/jnimij/public_html/cgi-bin/transporter.py</a> in <strong><module></strong>()</td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;79</small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print&nbsp;"&nbsp;&lt;/h1&gt;&nbsp;&lt;/center&gt;&nbsp;&lt;/body&gt;&nbsp;&lt;/html&gt;"<br>
</tt></font></td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;80</small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>
</tt></font></td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;81</small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>
</tt></font></td></tr>
<tr><td bgcolor="#ffccee"><tt>=&gt;<small>&nbsp;&nbsp;&nbsp;82</small>&nbsp;main()<br>
</tt></td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;83</small>&nbsp;<br>
</tt></font></td></tr>
<tr><td><small><font color="#909090"><strong>main</strong>&nbsp;= &lt;function main&gt;</font></small></td></tr></table>
<table width="100%" cellspacing=0 cellpadding=0 border=0>
<tr><td bgcolor="#d8bbff"><big>&nbsp;</big><a href="file:///home/2017/jnimij/public_html/cgi-bin/transporter.py">/home/2017/jnimij/public_html/cgi-bin/transporter.py</a> in <strong>main</strong>()</td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;27</small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;url&nbsp;=&nbsp;form.getvalue("url")<br>
</tt></font></td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;28</small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<br>
</tt></font></td></tr>
<tr><td bgcolor="#ffccee"><tt>=&gt;<small>&nbsp;&nbsp;&nbsp;29</small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;index&nbsp;=&nbsp;url.rfind('/')<br>
</tt></td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;30</small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;path_to_success&nbsp;=&nbsp;url[0:index]&nbsp;<br>
</tt></font></td></tr>
<tr><td><font color="#909090"><tt>&nbsp;&nbsp;<small>&nbsp;&nbsp;&nbsp;31</small>&nbsp;<br>
</tt></font></td></tr>
<tr><td><small><font color="#909090">index <em>undefined</em>, url <em>undefined</em></font></small></td></tr></table><p><strong>&lt;type 'exceptions.UnboundLocalError'&gt;</strong>: local variable 'url' referenced before assignment
<br><tt><small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</small>&nbsp;</tt>args&nbsp;=
("local variable 'url' referenced before assignment",)
<br><tt><small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</small>&nbsp;</tt>message&nbsp;=
"local variable 'url' referenced before assignment"


<!-- The above is a description of an error in a Python program, formatted
     for a Web browser because the 'cgitb' module was enabled.  In case you
     are not reading this in a Web browser, here is the original traceback:

Traceback (most recent call last):
  File "transporter.py", line 82, in &lt;module&gt;
    main()
  File "transporter.py", line 29, in main
    index = url.rfind('/')
UnboundLocalError: local variable 'url' referenced before assignment

-->

