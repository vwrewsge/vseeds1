
(module
  (import "js" "alert" (func $alert (param i32) (result i32)))
  (func (export "showAlert")
    i32.const 0
    i32.const 12
    call $alert
  )
)
