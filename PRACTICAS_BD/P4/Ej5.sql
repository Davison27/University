set serveroutput on;
DECLARE
    v_fecha1 votantes.fechanacimiento%type;
    v_fecha2 votantes.fechanacimiento%type;
BEGIN
    select fechanacimiento into v_fecha1
    from votantes
    where fechanacimiento=
        (select min(fechanacimiento)
        from votantes);
    
    select fechanacimiento into v_fecha2
    from votantes
    where fechanacimiento=
        (select max(fechanacimiento)
        from votantes);
    
    dbms_output.put_line(v_fecha1);
    dbms_output.put_line(v_fecha2);
    dbms_output.put_line((v_fecha2-v_fecha1)/365);
END;
