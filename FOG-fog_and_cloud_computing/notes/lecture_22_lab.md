# Lecture 22/5/24

# Topic: Lab10 (Kubernetes security, Lab recap)

## Admission control

K8s itself does not have granular API validation

- Mutate the request
  - add default values, modify labels
- Restrict the request
  - deny pods with specific labels
- Enforce policies

### Gatekeeper

Uses OPA to enforce policies

### OPA: Open Policy Agent

allows flexible API verification

```JSON
deny contains reason if {
    some container
    input_containers[container]
    not startswith(container.image, "unitn.it/")
    reason := "container image in illegal registry (must be unitn.it)"
}
```

if you try to deploy a pod with an image from docker hub:

```JSON
{
"deny": "container image in illegal registry (must be unitn.it)"
}
```

## Auditing

Each action in the cluster generates an audit event.
If enabled k8s logs everything that happens.
Provides a trail of what happened in the cluster.

Different logging levels are available