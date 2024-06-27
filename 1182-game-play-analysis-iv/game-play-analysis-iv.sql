# Write your MySQL query statement below
SELECT ROUND(SUM(
    CASE
        WHEN ACT.event_date = (
            SELECT DATE_ADD(MIN(ACT2.event_date), INTERVAL 1 DAY)
            FROM Activity ACT2
            WHERE ACT2.player_id = ACT.player_id
        ) THEN 1
        ELSE 0
    END
    ) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM Activity ACT