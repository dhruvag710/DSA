WITH managerReports AS(
    SELECT managerId
    FROM employee
    GROUP BY managerId
    HAVING COUNT(*)>=5
)

SELECT e.name
FROM employee AS e
JOIN managerReports as m
ON e.id=m.managerId;
