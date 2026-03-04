# Write your MySQL query statement below

select a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp), 3) as processing_time 
from Activity a1
join ACtivity a2 ON a1.machine_id = a2.machine_id AND a2.process_id = a2.process_id AND a1.activity_type = 'start' and a2.activity_type = 'end'
group by machine_id