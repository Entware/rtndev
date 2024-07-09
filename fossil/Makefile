# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2016-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=fossil
PKG_VERSION:=2.24
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-src-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.fossil-scm.org/home/tarball/66ee0beb9b47d827bde533fe6a1fb2ead4ceb1936468881b4fb621bd6bdfd862
PKG_HASH:=20c343d10b778f139b8515a4d70cb8b3d5d468c99f1f946468eea9cc7ab32869

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

TCL_VERSION:=$(shell grep ^TCL_MAJOR_VERSION ../../packages/lang/tcl/Makefile | cut -d= -f2)

TARGET_CFLAGS += \
	-DFOSSIL_ENABLE_SSL \
	-DFOSSIL_ENABLE_TCL \
	-DFOSSIL_ENABLE_TCL_STUBS \
	-DFOSSIL_ENABLE_TCL_PRIVATE_STUBS \
	-DFOSSIL_ENABLE_JSON \
	-DUSE_SYSTEM_SQLITE

TARGET_LDFLAGS += -lsqlite3 -lm -ltcl$(TCL_VERSION)

define Package/fossil/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fossil $(1)/opt/bin
endef

$(eval $(call BuildPackage,fossil))
