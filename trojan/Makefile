#
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=trojan
PKG_VERSION:=1.16.0
PKG_REV:=8606b7110fe79f8ab02d60c897f87ffb0a9b23f0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/trojan-gfw/trojan.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/trojan
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+boost-system +boost-program_options +libopenssl
	TITLE:=GFW bypass tool
	URL:=https://trojan-gfw.github.io/trojan/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/trojan/description
 An unidentifiable mechanism that helps you bypass GFW.
endef

CMAKE_OPTIONS += \
	-DENABLE_MYSQL=OFF \
	-DENABLE_REUSE_PORT=OFF \
	-DSYSTEMD_SERVICE=OFF

define Package/trojan/conffiles
/opt/etc/trojan/config.json
endef

define Package/trojan/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/trojan $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/trojan
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/trojan/config.json \
		$(1)/opt/etc/trojan
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) files/S22trojan $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,trojan))
