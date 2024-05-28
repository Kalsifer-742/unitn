# Lecture 17/5/24

# Topic: Lab09 (Kubernetes security)

## RBAC Role Based Access Control

fine grained control on who can access what in the cluster

- Roles
  - defines permissions for a namespace
- RoleBindings
  - bind roles to users or service accounts
- ClusterRoles and ClusterRoleBindings
  - same things but at the cluster level
  - very powerful and very risky

### Role

```YAML
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  namespace: default
  name: pod-reader
rules:
- apiGroups: [""] # "" indicates the core API group
  resources: ["pods"]
  verbs: ["get", "watch", "list"]
```

### RoleBinding

```YAML
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: read-pods
  namespace: default
subjects:
- kind: User
  name: jane
  apiGroup: rbac.authorization.k8s.io
roleRef:
  kind: Role # can also be ClusterRole
  name: pod-reader # this must match the name of the Role
  apiGroup: rbac.authorization.k8s.io
```

## Network policies

defines how pods communicate between them and the outside world. used to restrict traffic.

```YAML
apiVersion: networking.k8s.io/v1
kind: NetworkPolicy
metadata:
  name: test-network-policy
  namespace: default
spec:
  podSelector:
    matchLabels:
      role: db
  policyTypes:
  - Ingress
  - Egress
ingress:
- from:
  - ipBlock:
      cidr: 172.17.0.0/16
  - namespaceSelector:
      matchLabels:
        project: myproject
  - podSelector:
      matchLabels:
        role: frontend
ports:
- protocol: TCP
  port: 6379
```

## kube-bench

tool to check the security of the cluster. doesn't give any solutions. you must fix problems your self. it only does error reporting.

## gVisor

exercise of running a container with gVisor