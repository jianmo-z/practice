# Golang

## filename

```
$!{question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug})/$!{question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug})_test
```

## body

```
package $!velocityTool.camelCaseName(${question.titleSlug})

import "testing"

${question.content}

${question.code}

func Test$!velocityTool.camelCaseName(${question.titleSlug})(t *testing.T) {

}
```