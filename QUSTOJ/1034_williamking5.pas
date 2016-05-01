var
    x,y,z,len,i,j,k,m,n:longint;
    sum,tree:array[0..20,0..100000] of longint;
    he,left,right,l,r:array[1..300000] of longint;
    a:array[1..100000,0..1] of longint;
    v:array[1..100000] of 0..1;
procedure sort(h,t:longint);
var
    i,j,x,y,k:longint;
begin
    x:=a[(h+t)div 2,0];
    y:=a[(h+t)div 2,1];
    i:=h;j:=t;
    repeat
        while (a[i,0]<x) or ((a[i,0]=x)and(a[i,1]<y)) do
            inc(i);
        while (a[j,0]>x) or ((a[j,0]=x)and(a[j,1]>y)) do
            dec(j);
        if i<=j then begin
            k:=a[i,0];a[i,0]:=a[j,0];a[j,0]:=k;
            k:=a[i,1];a[i,1]:=a[j,1];a[j,1]:=k;
            inc(i);
            dec(j);
        end;
    until i>j;
    if i<t then sort(i,t);
    if j>h then sort(h,j);
end;
procedure build(root,ll,rr,h:longint);
begin
    l[root]:=ll;
    r[root]:=rr;
    he[root]:=h;
    if ll<>rr then begin
        inc(len);
        left[root]:=len;
        build(len,ll,(ll+rr)div 2,h+1);
        inc(len);
        right[root]:=len;
        build(len,(ll+rr)div 2+1,rr,h+1);
    end;
end;
procedure divide_h(root:longint);
var
    i,j,s:longint;
begin
    if l[root]=r[root] then exit;
    for i:=l[root] to r[root] do v[i]:=0;
    for i:=l[root] to r[root] do
    begin
        a[i,0]:=tree[he[root],i];
        a[i,1]:=i;
    end;
    sort(l[root],r[root]);
    for i:=l[root] to (l[root]+r[root])div 2 do
        v[a[i,1]]:=1;
    s:=0;j:=0;
    for i:=l[root] to r[root] do
        if v[i]=1 then begin
            tree[he[root]+1,l[root]+s]:=tree[he[root],i];
            inc(s);sum[he[root],i]:=s;
        end
        else begin
            tree[he[root]+1,(l[root]+r[root])div 2+1+j]:=tree[he[root],i];
            inc(j);sum[he[root],i]:=s;
        end;
    if left[root]<>0 then divide_h(left[root]);
    if right[root]<>0 then divide_h(right[root]);
end;
function kthnum(root,ll,rr,k:longint):longint;
var
    i,j,x:longint;
begin
    if l[root]=r[root] then exit(tree[he[root],l[root]]);
    if ll-1<l[root] then x:=0
    else x:=sum[he[root],ll-1];
    if k<=sum[he[root],rr]-x then exit(kthnum(left[root],l[left[root]]+x,l[left[root]]+sum[he[root],rr]-1,k))
    else exit(kthnum(right[root],l[right[root]]+ll-l[root]-x,r[right[root]]-((r[root]-rr)-(sum[he[root],r[root]]-sum[he[root],rr])),k-(sum[he[root],rr]-x)))
end;
begin
    readln(n,m);
    fillchar(sum,sizeof(sum),0);
    fillchar(tree,sizeof(tree),0);
    fillchar(left,sizeof(left),0);
    fillchar(right,sizeof(right),0);
    fillchar(l,sizeof(l),0);
    fillchar(r,sizeof(r),0);
    len:=1;
    build(1,1,n,0);

    for i:=1 to n do
        read(tree[0,i]);
    divide_h(1);
    for i:=1 to m do
    begin
        readln(x,y,z);
        writeln(kthnum(1,x,y,z));
    end;
end.
