# Write your MySQL query statement below
select s.student_id, s.student_name, sub.subject_name, COUNT(e.subject_name) AS attended_exams
from Students s cross join Subjects as sub left join Examinations e on s.student_id = e.student_id
AND sub.subject_name = e.subject_name
GROUP BY s.student_id, sub.subject_name
ORDER BY s.student_id, sub.subject_name;