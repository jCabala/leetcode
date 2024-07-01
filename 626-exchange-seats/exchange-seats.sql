SELECT 
    (CASE 
        WHEN id = CNT.cnt AND id % 2 = 1 THEN id
        WHEN id % 2 = 1 THEN id + 1
        ELSE id - 1
    END) AS id,
    student 
FROM Seat, (SELECT COUNT(id) AS cnt FROM SEAT) AS CNT
GROUP BY id
ORDER BY id

