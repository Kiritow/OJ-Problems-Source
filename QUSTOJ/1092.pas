var e:array[1..10] of longint;
w,d:array[1..50000] of longint;
i,m,n,j:longint;

procedure ss(x,y:longint);
var ii,jj,s,o,aa:longint;
begin
ii:=x;jj:=y;
s:=w[(x+y) shr 1];
aa:=d[(x+y) shr 1];
repeat
while (w[ii]>s) or ((w[ii]=s) and (d[ii]<aa)) do inc(ii);
while (w[jj]<s) or ((w[jj]=s) and (d[jj]>aa)) do dec(jj);
if ii<=jj then begin
o:=w[ii];w[ii]:=w[jj];w[jj]:=o;
o:=d[ii];d[ii]:=d[jj];d[jj]:=o;
inc(ii);dec(jj);
end;
until ii>jj;
if x<jj then ss(x,jj);
if ii<y then ss(ii,y);
end;

begin
readln(n,m);
for i:=1 to 10 do read(e[i]);
readln;
for i:=1 to n do read(w[i]);
for i:=1 to n do d[i]:=i;
ss(1,n);
for i:=1 to n do w[i]:=w[i]+e[(i-1) mod 10+1];
ss(1,n);
if m=0 then halt;
write(d[1]);
for i:=2 to m do write(' ',d[i]);
readln;
end.
