create or replace trigger trigger3
before insert or update on consultas for each row
BEGIN
    if :new.fecha > sysdate then
        insert into audit_table values('Hubo cambios en la fecha ' || :new.fecha || 'a' || sysdate, 'consultas');

        :new.fecha :=sysdate;
    end if;
END;

/*Compilamos */
update consultas set fecha=to_date('11/07/2020', 'DD/MM/YY') where idconsulta=3;        /*Actualizamos una consulta para comprobar que funciona el trigger*/

select *from consultas;         /*Vemos la tabla de consultas*/
select *from audit_table;       /*Vemos la tabla de audit_table*/