select round(count(a2.player_id)/count(distinct a1.player_id),2) as fraction
from (
    select player_id, min(event_date) as first_login
    from activity
    group by player_id
)as a1
left join activity as a2
 on a1.player_id = a2.player_id and a1.first_login + interval 1 day = a2.event_date