# Write your MySQL query statement below

SELECT 
    st.machine_id, 
    ROUND(AVG(et.timestamp - st.timestamp), 3) AS processing_time 
FROM 
    (SELECT machine_id, process_id, timestamp FROM Activity WHERE activity_type = 'start') AS st
INNER JOIN 
    (SELECT machine_id, process_id, timestamp FROM Activity WHERE activity_type = 'end') AS et 
    ON st.machine_id = et.machine_id AND st.process_id = et.process_id
GROUP BY 
    st.machine_id;