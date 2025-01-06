# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=go
PKG_VERSION:=1.23.4
PKG_RELEASE:=1

PKG_SOURCE:=go$(PKG_VERSION).src.tar.gz
PKG_SOURCE_URL:=https://dl.google.com/go
PKG_HASH:=ad345ac421e90814293a9699cca19dd5238251c3f687980bbcae28495b263531

BINTYPE:=$(shell uname -m | sed 's/i[3-6]86/386/;s/x86_64/amd64/')

# Strip is not recommended for go binaries. It may make binaries unusable
RSTRIP:="/bin/true"

PKG_BUILD_PARALLEL:=1
PKG_BUILD_FLAGS:=no-mips16

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/golang.mk

PKG_UNPACK:=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

define Package/go/Default
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=The Go Programming Language
	URL:=https://golang.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/go
	$(call Package/go/Default)
	VARIANT:=hf
endef

define Package/go_nohf
	$(call Package/go/Default)
	VARIANT:=nohf
	DEPENDS:=@(TARGET_armv7_2_6||TARGET_armv7_3_2)
endef

define Package/go/description
 Go is an open source programming language that makes it
 easy to build simple, reliable, and efficient software.
endef

Package/go_nohf/description=$(Package/go/description)

define Build/Prepare
	$(call Build/Prepare/Default)
endef

define Build/Compile
	( \
		cd $(PKG_BUILD_DIR)/src; \
		$(GO_VARS) GOROOT_BOOTSTRAP=$(STAGING_DIR_HOST)/go \
		./make.bash --no-banner; \
	)
	if [ -d "$(PKG_BUILD_DIR)/bin/linux_$(GOARCH)" ]; then \
		rm $(PKG_BUILD_DIR)/bin/go; \
		rm $(PKG_BUILD_DIR)/bin/gofmt; \
		mv $(PKG_BUILD_DIR)/bin/linux_$(GOARCH)/* $(PKG_BUILD_DIR)/bin/; \
		rm -rf $(PKG_BUILD_DIR)/bin/linux_$(GOARCH); \
	fi
	rm -rf $(PKG_BUILD_DIR)/pkg/bootstrap
	rm -rf $(PKG_BUILD_DIR)/pkg/obj
	[ "$(BINTYPE)" == "$(GOARCH)" ] || rm -rf $(PKG_BUILD_DIR)/pkg/linux_$(BINTYPE)
	[ "$(BINTYPE)" == "$(GOARCH)" ] || rm -rf $(PKG_BUILD_DIR)/pkg/tool/linux_$(BINTYPE)
endef

define Package/go/install
	$(INSTALL_DIR) $(1)/opt/bin/go
	$(CP) $(PKG_BUILD_DIR)/{api,bin,lib,misc,pkg,test,doc,src} $(1)/opt/bin/go
	# Entware specific: fix exec path in scripts
	$(FIND) $(1)/opt/bin/go -type f | $(XARGS) $(SED) \
		's,^#!.*bash,#!/opt/bin/bash,;s,^#!.*perl,#!/opt/bin/perl,'
	$(SED) 's,$(STAGING_DIR_HOST),/opt,' \
		$(1)/opt/bin/go/src/cmd/cgo/zdefaultcc.go \
		$(1)/opt/bin/go/src/cmd/go/internal/cfg/zdefaultcc.go
endef

Package/go_nohf/install=$(Package/go/install)

define Package/go/postinst
#!/bin/sh
echo "Please add /opt/bin/go/bin to your PATH"
echo "Please set GOROOT=/opt/bin/go environment variable to use GO compiler"
endef

Package/go_nohf/postinst=$(Package/go/postinst)

$(eval $(call BuildPackage,go))
$(eval $(call BuildPackage,go_nohf))
