#
# Copyright (C) 2016-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fossil
PKG_VERSION:=2.21
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-src-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.fossil-scm.org/home/tarball/f9aa474081f0618c76f4c2f4d6f0277a3fd480aa185d7da0b8b61b00fad1aa78
PKG_HASH:=195faf0b20c101834a809979d0a9cdf04a0dcbae1fdabae792c9db900b73bda0

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
