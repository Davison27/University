set serveroutput on;
DECLARE
    v_apellido votantes.nombrecompleto%type;
    v_dni votantes.dni%type;
BEGIN
    select dni into v_dni
    from votantes
    where fechanacimiento=
        (select min(fechanacimiento)
        from votantes);

    select substr(nombrecompleto,instr(nombrecompleto,' '),(instr(nombrecompleto,' ',1,2)-instr(nombrecompleto,' ')))
    into v_apellido
    from votantes
    where fechanacimiento=
        (select min(fechanacimiento)
        from votantes);
    dbms_output.put_line(v_apellido||',con dni: '||v_dni||' es el/la votante con más años');
END;
