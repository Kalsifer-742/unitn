# Written exam - 28/07/2023, just to have an idea regarding the level of detail that the exam requires

## Multiple Choice questions

**MC1** What is true about containers?

- [ ] containers are way lighter than VMs from the point of view of file size
- [ ] they cannot run on a system with a different kernel
- [ ] *some other option*
- [ ] *some other option*

**MC2** Considering a k-ary fat tree topology of degree k, which one is correct?

- [x] a switch has k ports
- [ ] it connects k^2-1 servers
- [ ] a core router has k^2 ports or *some other wrong value*
- [ ] an edge layer switch has IP 10.pod.switch.serverID or *some other wrong scheme*

**MC3** In a docker environment, secrets are securely passed:

- [ ] through an unencrypted network
- [ ] through environment variables passed through "docker run", because the host can't read them neither other processes/container
- [x] none of the answers
- [ ] it is fine to pass secrets at intermediate stage of a multi-stage build to be used and then removed with "Docker rm"

**MC4** How do you most frequently access OpenStack?

- [ ] API, CLI
- [ ] Horizon
- [x] API, CLI, Horizon
- [ ] SSH, API, CLI

**MC5** What does not apply to Kubernetes?

- [x] it's a PaaS which requires specific software versions and so on
- [ ] *something about load balancing*
- [ ] *something about replication*
- [ ] *something else which applies to k8s*

## Open questions

**O1** Google Big Table.

- Describe the data model, how google big table stores data. Is there a way to handle multiple versions of the same data?
- Knowing the tablet server's location, how is a write operation carried out?
- Once the memtable is filled/gets to a size threshold, what can be done? Does this help with system recovery?

**O2** In the context of x86 virtualization:

- How are system calls handled in the trap&emulate paradigm? (if you want you can draw a diagram alongside the explaination)
- Why is x86 considered non virtualizable? Have there been any solutions to this problem? (no need to get into too much detail, just say what the options are)
- Describe how paravirtualization in implemented. Is there any other hardware resource that can take advantage of paravirtualization? Compare the two kinds of paravirtualizations

**O3** Consider Vagrant, Ansible, Virtualbox:

- Explain what each of them does
- Through an example, explain how you can use them together
- Explain why it's useful to use them all together / at the same time

**O4** A Kubernetes cluster is made of one Master Node and three Worker Nodes, described in the configuration application.yml file (there were three pages of YAML). One of the Worker Nodes was labeled "cloud" while the other two were labeled "edge"; some of the resources on the configuration file had a label specifying either "cloud" or "edge". There were a frontend, a backend, something inbetween, a ClusterIP service and a NodePort service.

- Describe the aforementioned architecture and describe at least 4 control plane components running on the Master Node or on the Worker Nodes, and specify where they run. Use a sketch if you want, because sometimes sketches are worth more then a lot of words
- You deploy this architecture through ```kubectl create application.yml```. How are the pods scheduled in the cluster? At the end of the deployment, how many pods are running on each node?
- If a client tries to reach the cluster from its public IP, will the operation be successful? (the operation would fail since there was a mistake in the file, two port numbers were off by 1)

# Oral exams - 7/08/2023

The papers for this oral session were:

- J. Nam, S. Lee, H. Seo, P. Porras, V. Yegneswaran, and S. Shin, "BASTION: A Security Enforcement Network Stack for Container Networks", Usenix ATC 2020, available at: https://www.usenix.org/system/files/atc20-nam.pdf
- F. Faticanti, F. De Pellegrini, D. Siracusa, D. Santoro, and S. Cretti, ‘Throughput-Aware Partitioning and Placement of Applications in Fog Computing’, IEEE Transactions on Network and Service Management, vol. 17, no. 4, pp. 2436–2450, Dec. 2020, doi: 10.1109/TNSM.2020.3023011.

Notes:

- the grades were published late and the professor had us choose only one paper
- both students who did the oral exam found it alright, professor was pretty chill
- both students chose the paper on BASTION

Questions that popped up:

- why did you choose this paper
- what part of the paper did you find the most interesting?
- explain what the components of the system introduced by the paper do, and what problems they solve
- about the implementation, is it something they created from scratch or was there already something that they used? (for BASTION, they used BPF)
