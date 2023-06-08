set serveroutput on
create or replace 
function dept_highest(dname varchar) 
return varchar2 as
inst_max number;
instrname instructor.name%TYPE;
begin
	select max(salary)
	into inst_max
	from instructor 
	where dept_name=dname;

	select name
	into instrname
	from instructor
	where salary=inst_max and dept_name=dname;

	return inst_max || ' by ' || instrname;
end;
/