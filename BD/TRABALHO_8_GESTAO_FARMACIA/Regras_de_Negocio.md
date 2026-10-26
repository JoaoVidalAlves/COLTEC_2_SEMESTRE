# REGRAS DE NEGOCIO


### Usuario
|REGRA|TIPO|DESCRICAO| 
|:---:|:---:|:---|
RN01 | Usuario      | Todo usuário é cliente ou funcionário.|
RN02 | Usuario      | O usuário é identificado por CPF ou celular.|
RN03 | Funcionario  | Todo funcionário é um usuário, mas nem todo usuário é funcionário.|
RN04 | Funcionario  | O funcionário tem cargo e nível de acesso (administração/TI, gerente ou atendente).|
RN05 | Cliente      | Um cliente pode fazer vários pedidos, mas cada pedido pertence a um único cliente.|
RN06 | Cliente      | O cliente só visualiza a lista de produtos com preços e os próprios pedidos.
RN07 | Gerente      | Só o gerente pode alterar preços e criar promoções.
RN08 | Cliente      | Um cliente pode ter vários endereços, e o pedido de delivery usa um deles.
RN09 | Usuario      | Todo usuário com acesso ao sistema tem login e senha.

### Produto
|REGRA|TIPO|DESCRICAO| 
|:---:|:---:|:---|
RN01 | Produto      | Não é possível vender um produto sem estoque suficiente.
RN02 | Produto      | Todo produto pertence a uma categoria e tem preço, quantidade e validade.
RN03 | Produto      | Medicamentos que exigem receita só podem ser vendidos com a receita registrada.
RN04 | Produto      | Todo produto é fornecido por um ou mais fornecedores, e cada compra de fornecedor registra data, itens e quantidades.
RN05 | Produto      | Uma promoção tem período de validade e se aplica a um ou mais produtos.
RN06 | Produto      | Produto vencido não pode ser vendido.

### Pedido
|REGRA|TIPO|DESCRICAO| 
|:---:|:---:|:---|
RN01 | Pedido       | Todo pedido de delivery gera uma entrega com endereço, data e hora.
RN02 | Pedido       | Um pedido só é concluído após a confirmação de entrega.
RN03 | Pedido       | Todo pedido é registrado por um funcionário (atendente) com data e hora.|
RN04 | Pedido       | Um pedido tem um ou mais produtos, e um produto pode estar em vários pedidos.
RN05 | Pedido       | Cada item do pedido guarda a quantidade e o preço no momento da venda.
RN06 | Pedido       | Todo pedido tem uma forma de pagamento (dinheiro, cartão, Pix) e um valor total.
RN07 | Entrega      | Toda entrega é feita por um entregador (funcionário) e tem status (preparando, a caminho, entregue).
RN08 | Pedido       | Todo pedido tem status (aberto, pago, cancelado, concluído).
RN09 | Pedido       | Um pedido pode ser cancelado antes da entrega, e o estoque volta ao valor anterior.
RN10 | Pedido       | O pedido pode ser feito pela internet ou pelo telefone, e o canal fica registrado.

### Venda
|REGRA|TIPO|DESCRICAO| 
|:---:|:---:|:---|
RN01 | Venda        | Toda venda reduz o estoque.
RN02 | Venda        | Toda compra de fornecedor aumenta o estoque.

### Sistema
|REGRA|TIPO|DESCRICAO| 
|:---:|:---:|:---|
RN01 | Sistema      | O sistema gera alerta de estoque baixo e de produto próximo do vencimento.
