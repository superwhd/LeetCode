select  Score, 
       (
        select  count (distinct  Score) +  1
        from  Scores as  S2 
        where  S2.Score >  S1.Score
       ) as  Rank
from  Scores as  S1
order  by Rank
