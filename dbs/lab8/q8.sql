set serveroutput on
declare
	name instructor.name%TYPE;
begin

	select name 
	into name
	from instructor
	where name='&name';

	dbms_output.put_line(name||' found');

	exception
	when no_data_found then 
		dbms_output.put_line('no rows found');
	when dup_val_on_index then 
		dbms_output.put_line('multiple rows found');
end;
/