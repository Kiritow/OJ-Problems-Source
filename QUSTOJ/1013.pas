var x,y:array[0..100010]of double;
n:longint;
procedure init;
var i:longint;
begin
readln(n);
for i:=1 to n do
readln(x[i],y[i]);
end;
procedure kp(st,ed:longint);
var i,j:longint;
q,t:double;
begin
i:=st;
j:=ed;
q:=x[(i+j)div 2];
repeat
while x[i]<q do inc(i);
while x[j]>q do dec(j);
if i<=j then
begin
t:=x[i];x[i]:=x[j];x[j]:=t;
t:=y[i];y[i]:=y[j];y[j]:=t;
inc(i);dec(j);
end;
until i>j;
if st<j then kp(st,j);
if i<ed then kp(i,ed);
end;
function dis(i,j:longint):double;
var p,q:int64;
begin
dis:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
end;
procedure main;
var min,l:double;
i,j,k:longint;
begin
kp(1,n);
min:=1e10;
for i:=1 to n do
begin
j:=i+1;
while (x[j]-x[i]<min)and(j<=n) do inc(j);
for k:=i+1 to j-1 do
begin
l:=dis(i,k);
if min>l then min:=l;
end;
end;
writeln(min:0:3);
end;
begin
init;
main;
end.
