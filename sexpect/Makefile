#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sexpect
PKG_VERSION:=2.3.8
PKG_REV:=dce28740eacd8cf468209b447ee194d937dbf12d
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/clarkwang/sexpect.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=cf32cf9f574d2061845feac4ff45820009e95a47e62100eef8581856d351804e

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/sexpect
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Terminal
	TITLE:=another implementation of Expect
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/sexpect/description
 Unlike Expect (Tcl), Expect.pm (Perl), Pexpect (Python) or other similar
 Expect implementations, sexpect is not bound to any specific programming
 languages so it can be used with Shells (Bash, Ksh, Zsh, ...) and any
 other languages which support running external commands. Users who write
 shell scripts would love this because they don't have to learn other languages
 just to use the Expect feature.

 Another interesting sexpect feature is that the spawned child process is
 running in background. You can attach to and detach from it as needed.
endef

define Package/sexpect/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/sexpect $(1)/opt/bin
endef

$(eval $(call BuildPackage,sexpect))
