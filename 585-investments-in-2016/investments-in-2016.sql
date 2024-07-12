SELECT
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM
    Insurance SN
WHERE
    (
        SELECT 
            COUNT(pid)
        FROM
            Insurance
        WHERE
            tiv_2015 = SN.tiv_2015
    ) > 1
AND
    (
        SELECT 
            COUNT(pid)
        FROM
            Insurance
        WHERE
            lat = SN.lat
        AND
            lon = SN.lon
    ) = 1