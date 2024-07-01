SELECT person_name
FROM Queue Q
WHERE (
    SELECT SUM(weight)
    FROM Queue
    WHERE turn <= Q.turn 
) <= 1000
AND ((
        SELECT SUM(weight)
        FROM Queue
        WHERE turn <= Q.turn + 1
    ) > 1000 
    OR
        turn IN (
            SELECT COUNT(person_id)
            FROM Queue
    )
)