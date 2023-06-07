set SERVEROUTPUT ON

declare
    cursor C is select * from takes where course_id = 'CS-101';
    creds student.tot_cred%TYPE;
begin
    for I in C
    loop
        select tot_cred 
	into creds from student where ID = I.ID;
        if creds < 30 then
            delete from takes where ID = I.ID and course_id = I.course_id;
        end if;
    end loop;
end;
/