set serveroutput on;
DECLARE
    type tabla_hash is Table of FLOAT index by VARCHAR2(100);
    mitabla tabla_hash;
    nombre VARCHAR2(100);

    CURSOR resultados IS select p.nombreCompleto, e.resultado
    from partidos p, eventos_resultados e
    where p.idpartido=e.partido;
BEGIN
    FOR resultado IN resultados LOOP
        if mitabla.exists(resulato.nombreCompleto) THEN
            mitabla(resultado.nombreCompleto) := mitabla(resultado.nombreCompleto) + resultado.resultado;

        else
            mitabla(resultado.nombreCompleto) := resultado.resultado;
        END IF;
    END LOOP;

    nombre :=mitabla.FIRST;
    while nombre IS NOT NULL LOOP  
        dbms_output.put_line(nombre||' => '||mitabla(nombre));
        nombre:=mitabla.next(nombre);
    END LOOP;
END;