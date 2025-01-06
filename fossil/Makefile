# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2016-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=fossil
PKG_VERSION:=2.25
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-src-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.fossil-scm.org/home/tarball/8f798279d5f7c3288099915f2ea88c57b6d6039f3f05eac5e237897af33376dc
PKG_HASH:=611cfa50d08899eb993a5f475f988b4512366cded82688c906cf913e5191b525
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

MAKE_VARS += \
	MAKE_COMPILATION_DB=no

define Package/fossil/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fossil $(1)/opt/bin
endef

$(eval $(call BuildPackage,fossil))
