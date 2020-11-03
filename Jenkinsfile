pipeline {
    agent {
        label 'hemtt'
    }

    stages {
        stage('Keys') {
            steps {
                withCredentials([
                    file(credentialsId: 'SFP_ITC_LAND_SYSTEMS_PRIVATE_KEY', variable: 'SFP_ITC_LAND_SYSTEMS_PRIVATE_KEY'),
                    file(credentialsId: 'SFP_ITC_LAND_SYSTEMS_PUBLIC_KEY', variable: 'SFP_ITC_LAND_SYSTEMS_PUBLIC_KEY')
                ]) {
                    bat 'mkdir releases\\keys'
                    bat 'copy %SFP_ITC_LAND_SYSTEMS_PRIVATE_KEY% releases\\keys'
                    bat 'copy %SFP_ITC_LAND_SYSTEMS_PUBLIC_KEY% releases\\keys'
                }
            }
        }

        stage('Build') {
            steps {
                bat 'hemtt build --release' 
            }
        }

        stage('Archive Build') {
            steps {
                archiveArtifacts artifacts: 'releases/1.0.0/**/*'
            }
        }

        stage('Publish to Steam Workshop') {
            when {
                branch 'master'
            }

            steps {
                publishSteamWorkshop '2276396320', 'releases/1.0.0/@sfp_itc_land_systems_compat', "https://github.com/SwedishForcesPack/SFP-ITC-Land-Systems-Compatibility/commit/${env.GIT_COMMIT}"
            }
        }
    }
}

void publishSteamWorkshop(String id, String mod, String changeNote) {
    bat "\"C:\\Program Files (x86)\\Steam\\SteamApps\\common\\Arma 3 Tools\\Publisher\\PublisherCmd.exe\" update /changeNote:$changeNote /id:$id /path:$mod"
}
