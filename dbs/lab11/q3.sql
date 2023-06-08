create or replace trigger instrInsert
before insert on instructor
for each row
declare
sal number;
bud number;
begin
	if length(trim(translate(:NEW.name, 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', ' '))) > 0 then
		raise_application_error(-20100,'name must contain only alphabets');
	else
    		if :NEW.salary < 1 then
			raise_application_error(-20100,'salary cannot be negative');
    		else
        		select sum(salary) 
			into sal 
			from instructor 
			where dept_name = :NEW.dept_name;
        		
			select budget 
			into bud 
			from department where dept_name = :NEW.dept_name;
        		
			if sal +:NEW.salary>bud then
				raise_application_error(-20100,'not enough department budget');
        		end if;
   		end if;
	end if;
end;
/