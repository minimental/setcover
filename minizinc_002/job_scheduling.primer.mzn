/*
 * M I N I Z I N C   P R I M E R
 * =============================
 *
 * This MiniZinc primer aims at scheduling a given set of tasks s.t. end time is minimized
 *
 * Taken from the MiniZinc Handbook, Release 2.4.3 (Mar 03 2020), Part 2, "A MiniZinc Tutorial", section 2.2.5 "Complex Constraints"
 * https://www.minizinc.org/doc-latest/index.html
 * 
 * "MiniZinc is a [high-level abstraction] language for specifying constrained optimization and decision problems over integers and real numbers."
 *
 */
 
% jobs and tasks are organized via enums; a set of tasks form a job
% to stress that an identifier is of type enum, capitalize it
% ...
% no, wait
% ...
% my definition of `job' and `task' does not seem to be correct
% because the overall duration is formed as the sum of duration of all jobs and tasks
%
% so what's the difference?
%
% i'm not in the mood for reverse engineering
%
% manual says:
%
% "In job shop scheduling we have a set of jobs, each consisting of a sequence of tasks on separate machines:"
%
% `separate machines' implies that these tasks can be done in parallel
%
% maybe a task could be sth like `drill holes', and a job could be sth like `manufacture adaptor plate'
%
% drilling holes for adaptor plate 1 might take longer than drilling holes for adaptor plate 2
% this fact justifies that jobs and tasks are organized in an array s.t. every possible permutation may occur
%
% what if there are tasks that do not occur in a job?
% then they do not take time in the job and account for 0
%
% Ok.
% So we have a set of jobs, and a set of tasks.
% The mapping which tasks need to be done in which job makes forms a basis for an optimization problem
%
% It's important to note that one task need to be finished, before the next can begin
% Like in making threads: you cannot make a thread if you have not drilled a hole before
%
% If there was only one job, there wouldn't be any problem: start with task 1, end with task N.
%
% But since we have many jobs, we may benefit from parallelizing it to minimize end time.
% S.t. two machines run simultaneously to finish two jobs
% If the jobs need the exact same sequence and number of tasks, then you would feed the machines phase shifted by the longest task to minimize end time

/*
 * P A R A M E T E R S
 * ===================
 */

enum JOB;
enum TASK;

% which tasks are included in which job?
% (external data / input)
array[JOB, TASK] of int: task_duration;

% the last task
TASK: last_task = max(TASK);

% sum over all durations is maximum duration
int: max_duration = sum (j in JOB, t in TASK) (task_duration[j, t]);

/*
 * D E C I S I O N   V A R I A B L E S
 * ===================================
 */
% question is when to start tasks
array[JOB, TASK] of var 0..max_duration: start_time;

% In my first draft of a solution, I forgot to add an end time as a free variable
% I don't if this is strictly required, since the last start time plus the duration of the task could be required to be minimized.
% For now, I don't know if there's the need to introduce yet another decision variable for the end time
%
% Would it be the same to require the sum of all last start times to be as small as possible?
% But then, individual start times could be large while others could be small.
% And end time is sth like an infinity norm.
% So maybe it makes sense to introduce end time as yet another decision variable.

var 0..max_duration: end_time;

/*
 * C O N S T R A I N T S
 * =====================
 */

% constraint: tasks of the _same_ job need to be done in sequence
constraint forall (j in JOB) (
	forall (t in TASK where t < last_task) (start_time[j, enum_next(TASK, t)] >= start_time[j, t] + task_duration[j, t]) /\ start_time[j, last_task] + task_duration[j, last_task] <= end_time
);

% constraint: tasks of _different_ jobs may not overlap (there is exactly one machine dedicated for one task)
% the disjunction allows for changing the sequence:
% to get different jobs done, it may take shorter to first do the task for job 2 than for job 1
constraint forall (t in TASK) (
	forall (j1,j2 in JOB where j1 < j2) (start_time[j1,t] + task_duration[j1,t] <= start_time[j2,t] \/ start_time[j2,t] + task_duration[j2,t] <= start_time[j1,t])
);

solve minimize end_time;