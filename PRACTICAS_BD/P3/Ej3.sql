select siglas 
from partidos
where idpartido=any
    (select partido
    from eventos_resultados
    group by partido
    having count (*)=
        (select max(participaciones)
        from 
            (select partido, count(*) participaciones
            from eventos_resultados
            group by partido)
        )
    )