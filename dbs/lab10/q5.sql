set serveroutput on
create or replace 
function square(n integer)
return integer as 
begin
    return n * n;
end;
/

declare
n integer;
begin
    n := '&number';
    dbms_output.put_line('square of ' || n || ' is ' || square(n));
end;
/