#!/bin/bash
if [[ $# -lt 1 ]]; then
   echo "Usage: $0 <arguments to qsub>"
   echo ""
   echo 'At a minimum, you need to supply the queue to use, e.g., "-q long"'
   exit 1
fi
jid=`qsub $* -j oe -o create_run_scripts_test/log/ -N l2_fp -J 0-4 create_run_scripts_test/l2_fp_job.sh`
do_aggregate=False
if [[ "$do_aggregate" == "True" ]]; then
   # Wait for job to get into torque, otherwise dependency doesn't seem
   # to work right (this appears to be a bug, as of 10/4/2011, but an
   # easy one to work around)
   sleep 5                      
   # afteranyarray would be preferable, since afterokarray won't run if any
   # of the jobs fails. However at least with our current version of torque
   # (10/4/2011) afteranyarray doesn't actually work, even though the
   # documentation claims that it does. We verified that afterokarray works
   # and afteranyarray doesn't by running some simple tests in torque
   jid2=`qsub $* -j oe -o create_run_scripts_test/log/qsub_aggregate.log -N aggregate -W depend=afterok:$jid create_run_scripts_test/aggregate.sh`
fi
# The buildbot regression scripts depend on the output from qsub, so go ahead and write that
# out
echo $jid
