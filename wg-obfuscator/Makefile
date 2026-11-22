# SPDX-License-Identifier: GPL-2.0-only

include $(TOPDIR)/rules.mk

PKG_NAME:=wg-obfuscator
PKG_VERSION:=1.6
PKG_RELEASE:=1
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/ClusterM/wg-obfuscator/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=57d7d02a84f198a0fde8bf8f37673b517e27fa83c0ac9305b480ae41e428e4e2
PKG_LICENSE:=GPL-3.0-only
PKG_LICENSE_FILES:=LICENSE
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/wg-obfuscator
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=VPN
	TITLE:=WireGuard traffic obfuscation utility
	URL:=https://github.com/ClusterM/wg-obfuscator
	DEPENDS:=+libpthread +libatomic
endef

define Package/wg-obfuscator/description
 WireGuard Obfuscator - simple obfuscator for WireGuard.
 Useful if your ISP/government blocks WireGuard traffic.
endef

MAKE_FLAGS += \
	CC="$(TARGET_CC)" \
	CFLAGS="$(TARGET_CPPFLAGS) $(TARGET_CFLAGS) -pthread" \
	LDFLAGS="$(TARGET_LDFLAGS) -pthread -latomic" \
	RELEASE=1

define Package/wg-obfuscator/conffiles
/opt/etc/wg-obfuscator.conf
endef

define Package/wg-obfuscator/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/etc
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/wg-obfuscator $(1)/opt/bin/
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/wg-obfuscator.conf $(1)/opt/etc/
endef

$(eval $(call BuildPackage,wg-obfuscator))
