#
# Copyright (C) 2016-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fossil
PKG_VERSION:=2.16
PKG_RELEASE:=0

PKG_SOURCE:=$(PKG_NAME)-src-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://fossil-scm.org/home/tarball/7aedd5675883d4412cf20917d340b6985e3ecb842e88a39f135df034b2d5f4d3
PKG_HASH:=fab37e8093932b06b586e99a792bf9b20d00d530764b5bddb1d9a63c8cdafa14


PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-src-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/fossil
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Version Control Systems
	DEPENDS:=+libopenssl +libsqlite3 +tcl
	TITLE:=software CMS
	URL:=https://www.fossil-scm.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/fossil/description
 Fossil is a self-contained, high-reliability, distributed software
 configuration management system, including Bug Tracking, Wiki, Forum,
 and Technotes.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(LN) $(PKG_BUILD_DIR)/Makefile.classic $(PKG_BUILD_DIR)/Makefile
endef

define Build/Configure
endef

TARGET_CFLAGS += \
	-DFOSSIL_ENABLE_SSL \
	-DFOSSIL_ENABLE_TCL \
	-DFOSSIL_ENABLE_TCL_STUBS \
	-DFOSSIL_ENABLE_TCL_PRIVATE_STUBS \
	-DFOSSIL_ENABLE_JSON \
	-DUSE_SYSTEM_SQLITE

TARGET_LDFLAGS += -lsqlite3 -lm -ltcl8.5

define Package/fossil/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fossil $(1)/opt/bin
endef

$(eval $(call BuildPackage,fossil))
