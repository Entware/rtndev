#
# Copyright (C) 2016-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fossil
PKG_VERSION:=2.15.1
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-src-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.fossil-scm.org/fossil/uv
PKG_HASH:=80d27923c663b2a2c710f8ae8cd549862e04f8c04285706274c34ae3c8ca17d1

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
