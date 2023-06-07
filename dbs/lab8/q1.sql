set serveroutput on
declare
	pl_rollno StudentTable.gpa%TYPE;
	pl_row StudentTable%ROWTYPE;
begin
	pl_rollno := &RollNum;

	select * 
	into pl_row
	from StudentTable
	where rollno=pl_rollno;

	dbms_output.put_line('gpa of roll number '||pl_row.rollno||' is '||pl_row.gpa);
end;
/
