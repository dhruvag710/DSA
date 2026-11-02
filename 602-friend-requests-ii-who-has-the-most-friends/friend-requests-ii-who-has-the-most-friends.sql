WITH newTable AS(
    SELECT requester_id as id
    from RequestAccepted

    UNION ALL

    SELECT accepter_id as id
    from RequestAccepted
)

SELECT id, COUNT(*) AS num
from newTable
group by id
order by num desc
limit 1;