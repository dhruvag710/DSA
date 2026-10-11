WITH new_table AS(
    SELECT id, student,
    CASE WHEN id%2=0 THEN id-1
    WHEN id%2!=0 AND id= (SELECT MAX(id) FROM Seat) THEN id
    ELSE id+1
    END AS updated_id
    FROM Seat
)

SELECT updated_id AS id, student
FROM new_table
ORDER BY id ASC;