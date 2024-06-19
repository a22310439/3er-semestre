import React, { useState } from 'react';
import '../App.css';

const About = () => {
    const [selectedSection, setSelectedSection] = useState('mission');

    const renderContent = () => {
        switch (selectedSection) {
            case 'mission':
                return (
                    <div className="section-content">
                        <h2>Nuestra Misión</h2>
                        <p>Ser líder en la promoción del desarrollo competente del capital humano y empresarial en la República Mexicana y Latinoamérica, proporcionando programas educativos, capacitación especializada y certificaciones de calidad avaladas por la SEP. A través de nuestra dedicación a la excelencia académica, la innovación continua y la colaboración con socios estratégicos, buscamos ser un catalizador para el progreso económico y social en nuestras comunidades, contribuyendo así al éxito sostenible de nuestros clientes y al bienestar general de la sociedad.</p>
                    </div>
                );
            case 'vision':
                return (
                    <div className="section-content">
                        <h2>Nuestra Visión</h2>
                        <p>Convertirnos en un motor de transformación que empodera a las personas y fortalece a las empresas a través de la educación, capacitación y certificación de capital humano. Aspiramos a establecer alianzas estratégicas con actores clave en el ámbito empresarial, académico y gubernamental, para ampliar nuestro impacto y contribuir de manera significativa al desarrollo económico y social de la región y Latinoamérica. Esta visión refleja nuestro compromiso con la excelencia, la innovación y el crecimiento sostenible, con el objetivo de crear un futuro más próspero y equitativo para todos.</p>
                    </div>
                );
            case 'philosophy':
                return (
                    <div className="section-content">
                        <h2>Nuestra Filosofía</h2>
                        <p>Nuestra filosofía se basa en la convicción de que la educación y el desarrollo del capital humano son fundamentales para el progreso individual y colectivo. Nos comprometemos a ofrecer programas educativos y de capacitación de alta calidad, promoviendo un entorno de aprendizaje dinámico y colaborativo que fomente el pensamiento crítico y la creatividad. Creemos en la importancia de la colaboración con diversos actores para garantizar la relevancia de nuestros programas y contribuir al desarrollo económico, social y cultural de la región y Latinoamérica. Nuestra filosofía se centra en la excelencia, la innovación y la responsabilidad social, con el objetivo de empoderar a las personas y construir un futuro más próspero y equitativo para todos.</p>
                    </div>
                );
            default:
                return null;
        }
    };

    return (
        <div className="content">
            <h1>Sobre Nosotros</h1>
            <p>El Instituto Punto Alejandría es una institución dedicada a la formación y certificación de competencias profesionales. Nuestro objetivo es proporcionar las herramientas y el conocimiento necesario para que los profesionales se destaquen en sus respectivos campos.</p>
            <p>Contamos con un equipo de expertos altamente cualificados y con amplia experiencia en diversas áreas de conocimiento. Nuestro enfoque está en la calidad educativa y en el desarrollo integral de nuestros participantes.</p>
            <div className="selector-buttons">
                <button onClick={() => setSelectedSection('mission')}>Misión</button>
                <button onClick={() => setSelectedSection('vision')}>Visión</button>
                <button onClick={() => setSelectedSection('philosophy')}>Filosofía</button>
            </div>
            {renderContent()}
        </div>
    );
};

export default About;
