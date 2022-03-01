select v.dni "VOTANTE", count(c.votante)
from votantes v, consultas c 
where v.dni=c.votante
and v.dni!=
    (select dni 
    from votantes
    where fechanacimiento =
        (select min(fechanacimiento)
        from votantes 
        where fechanacimiento>
            (select min(fechanacimiento)
            from votantes)
        )
    )
group by v.dni
order by (count(c.votante)) desc