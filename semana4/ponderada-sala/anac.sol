// SPDX-License-Identifier: MIT
// Versão do solidity
pragma solidity ^0.8.0;

// Definindo o contrato Anac
contract Anac {
    
    // Variáveis de ambiente
    uint256 private idade = 18; // Variável de ambiente para a idade
    address private owner; // Variável para armazenar o endereço do dono do contrato

    // Evento emitido quando a idade é alterada
    event IdadeAlterada(uint256 novaIdade);

    // Modificador para garantir que apenas o dono pode executar uma função
    modifier apenasDono() {
        require(msg.sender == owner, "Apenas o dono pode executar esta funcao");
        _;
    }

    // Construtor que define o dono como o criador do contrato
    constructor() {
        owner = msg.sender;
    }

    // Função para obter a idade atual
    function getIdade() external view returns (uint256) {
        return idade;
    }

    // Função para definir a idade (apenas o dono pode executar)
    function setIdade(uint256 novaIdade) external apenasDono {
        idade = novaIdade;
        emit IdadeAlterada(novaIdade);
    }
}
