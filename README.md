# DEVGRU

🏆 **FPS 장르의 군사 테마 슈팅 게임**  

---

## 🎥 데모 영상

<a href="https://www.youtube.com/watch?v=9HvueqfVU3o">
  <img src="https://img.youtube.com/vi/9HvueqfVU3o/0.jpg" alt="데모 영상" width="300"/>
</a>
<br>
<b>DEVGRU 데모 영상</b>


---

## 🏃 프로젝트 개요

**DEVGRU**는 군사 기지에서 상대 팀을 섬멸하는 것을 목표로 하는 FPS(1인칭 슈팅) 장르의 게임입니다.  
- **개발 기간:** 2024.07.14 - 2024.09.23  
- **개발 인원:** 2명  
- **엔진 버전:** Unreal Engine 5.4.2  
- **개발 환경:** 주요 기능은 C++로 구현하였으며, 타임라인 및 카메라 흔들림 등의 기능은 블루프린트로 보조 개발.  

본 프로젝트에서 **무기 시스템 구현**을 주도적으로 담당했습니다.

---

## 🔧 구현에 참여한 핵심 기능

### 1️⃣ WeaponManagerComponent & WeaponActionComponent  

캐릭터에 컴포넌트 형식으로 부착되어 무기와 관련된 기능을 모듈화하여 관리합니다.  

#### WeaponManagerComponent  
- **주요 역할:**  
  - 소지 무기 관리  
  - 탄약 상태 추적  
  - 무기 교체 로직 처리  

#### WeaponActionComponent  
- **주요 역할:**  
  - 조준, 공격, 재장전 등 무기 동작 관리  
  - 크로스헤어 표시 및 반동 애니메이션 처리  

🔹 **구현 방식:**  
- 각 기능을 독립된 컴포넌트로 분리하여 모듈화.  
- 다른 컴포넌트와의 상호작용이 필요한 경우, `CharacterState` 변수를 통해 정보 전달.  
- 네트워크 최적화를 위해 `CharacterState` 변수만 Replicate하여 부하 최소화.  

![ComponentUML](https://github.com/user-attachments/assets/19576615-c458-4571-b9f9-a32e75051327)

🔹 **예시:**  
```cpp
// WeaponActionComponent에서 재장전 호출
void WeaponActionComponent::Reload()
{
  ...
  OwnerShooterCharacter->SetCharacterState(ECharacterState::ECS_Reloading);
  OwnerShooterCharacter->HandleCharacterState();
  ...
}

// CharacterAnimationComponent에서 애니메이션 처리할 수 있도록 전달
void AShooterCharacter::HandleCharacterState()
{
	...
  case ECharacterState::ECS_Reloading:
  	WeaponActionComponent->StopAiming();
  	CharacterAnimationComponent->PlayReloadMontage();
    break;
  ...
}
```
---
### 2️⃣ 무기 시스템 설계 및 구현
다양한 무기 유형을 계층적으로 설계하고, 각 유형별 동작을 구현했습니다.

#### 계층 구조
- Weapon (기본 클래스)
  - RangedWeapon (원거리 무기)
    - FirearmWeapon (총기)
      - Rifle: 발사체(Projectile) 방식으로 구현
      - Pistol: 라인트레이스(Line Trace)를 통한 히트스캔 방식
    - ThrowableWeapon (투척 무기)
      - Grenade: ThrowWeapon() 호출 시 FireGrenade()로 수류탄 발사
  - MeleeWeapon (근접 무기): 미구현 상태

![WeaponUML](https://github.com/user-attachments/assets/cefff2ba-6e38-46a0-9672-3a76940ecddc)

#### 🔹 주요 기능:
- `FirearmWeapon`: 자동 연사 여부, 탄피 배출, 재장전 애니메이션 지원.
- `ThrowableWeapon`: 투척 동작과 발사 로직 분리.

#### 📌 결과:
- 다양한 무기 유형을 체계적으로 관리 가능.
- 확장성을 고려한 설계로 향후 다양한 종류의 무기 추가 용이.
---
