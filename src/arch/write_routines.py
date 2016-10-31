exceptions = [
  False,
  False,
  False,
  False,
  False,
  False,
  False,
  False,
  True,
  False,
  True,
  True,
  True,
  True,
  True,
  False,
  False,
  False,
  False
]

def generate_isrs():
    f = open("output.S", 'w')
    routine_with_code = '''
isr{num}:
    cli
    push byte {num}
    jmp isr_common_stub\n
    '''
    routine_wo_code = '''
isr{num}:
    cli
    push byte 0
    push byte {num}
    jmp isr_common_stub\n
    '''
    for i, b  in enumerate(exceptions):
        if b:
            f.write(routine_with_code.format(num = i))
        else:
            f.write(routine_wo_code.format(num = i))
    for i in range(19, 32):
        f.write(routine_wo_code.format(num = i))
def generate_irq_handlers():
    f = open("irqs.S", 'w')
    routine = '''
irq{num}:
    cli
    push byte 0
    push byte {idt_num}
    jmp irq_common_stub'''

    for i in range(0, 16):
        f.write(routine.format(num = i, idt_num = 32 + i))



#generate_isrs()
generate_irq_handlers()
